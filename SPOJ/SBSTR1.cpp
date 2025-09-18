// bfgen_full.cpp
// Generates a Brainf**k program that solves SPOJ SBSTR1:
// - handles 24 input lines
// - each line: 10-bit A, space, 5-bit B
// - checks B as substring in A (positions 0..5)
// - prints '1' or '0' with newline per line
//
// Master: informal, human style comments in this C++ only.
// The BF emitted contains NO parentheses-comments (pure BF commands only).

#include <bits/stdc++.h>
using namespace std;

string rep(char c, int n){
    return string(max(0,n), c);
}

int main(){
    string bf;

    // Helper to append moves to a given absolute cell index from current pointer position.
    // But generator will manage pointer relative moves explicitly, so we directly emit moves.

    // We'll build one "line handler" block (reads A,B -> checks positions -> outputs),
    // then duplicate it 24 times because SPOJ uses exactly 24 lines.
    //
    // Tape layout for each run (we reuse same tape for each line):
    // cells 0..9  : A bits (0/1)   (A[0] at cell 0)
    // cell 10     : space (ignored)
    // cells 11..15: B bits (0/1)   (B[0] at cell 11)
    // cell 16     : match flag (0/1)  (set to 1 if any position matches)
    // cell 17..25 : temporaries used during comparisons
    //
    // We'll ensure after each line run we clear transient cells so next line is fresh.

    // For clarity we will:
    //  - read A[0..9] into 0..9, converting ASCII '0'/'1' -> 0/1 by subtracting 48
    //  - read space into cell 10 then zero it
    //  - read B[0..4] into 11..15 converting ASCII
    //  - set cell16 = 0 (match flag)
    //  - for pos = 0..5:
    //       - compute mismatch = OR over i=0..4 (A[pos+i] XOR B[i])
    //         We detect XOR by copying A and B and subtracting; since bits are 0/1,
    //         XOR == 1 iff values differ.
    //       - if mismatch == 0 -> set match flag = 1 and break out of pos loop
    //  - output result based on match flag
    //
    // Implementation notes:
    //  - Copy pattern used: [->+>+<<] then >>[ - << + >> ] restores original
    //    leaving a copy in the intermediate cell.
    //  - We keep pointer disciplined: after each op we return pointer to a known cell.
    //  - After finishing a line we zero cells 0..17 so next line starts clean.

    // We'll create one block called line_bf and then repeat it 24 times.
    string line;
    auto append = [&](const string &s){ line += s; };

    // 1) Read A[0..9] and convert ascii to numeric by subtracting 48 ('0')
    // pointer starts at cell 0
    for(int i=0;i<10;i++){
        // read to cell i (pointer already at i)
        append(",");            // read char
        append(rep('-',48));    // ascii '0' -> 0, '1' -> 1
        if(i < 9) append(">");  // move right to next cell
    }
    // pointer now at cell 9

    // read space into cell 10 and clear it
    append(">"); append(","); append("[-]"); // clear space
    // pointer at cell 10

    // read B[0..4] into cells 11..15
    for(int j=0;j<5;j++){
        append(">");   // move to next cell
        append(",");   // read char
        append(rep('-',48)); // convert to 0/1
    }
    // pointer at cell 15

    // clear match flag at cell 16
    append(">"); append("[-]"); // c16 = 0
    // pointer at cell 16

    // We'll iterate positions p = 0..5
    for(int p=0;p<=5;p++){
        // We'll compute mismatch into temp cell 17: set to 0 initially
        append(">"); append("[-]"); // c17 = 0
        append("<"); // back to c16

        // For each k=0..4 compute XOR of A[p+k] and B[k]
        for(int k=0;k<5;k++){
            int acell = p + k;      // A cell index
            int bcell = 11 + k;     // B cell index

            // Move pointer from current (c16) to acell
            int cur = 16;
            int target = acell;
            if(target < cur) append(rep('<', cur - target));
            else if(target > cur) append(rep('>', target - cur));
            // pointer at acell

            // Copy A[acell] into acell+1 and acell+2 (zeroing acell temporarily)
            append("[->+>+<<]");    // now acell == 0, copies at acell+1 and +2
            append(">>");           // at acell+2
            // restore A from acell+2
            append("[ - << + >> ]"); // restore into acell, leaves a copy at acell+1
            append("<"); // move to acell+1 (the copy)

            // Transfer copy (acell+1) to mismatch cell (c17) destructively:
            // while copy>0: copy-- ; go to c17 and toggle/increment
            int moves_right = 17 - (acell+1); // steps to c17
            append("[");
            append("-"); // decrement source
            append(rep('>', moves_right));
            append("+"); // add to mismatch
            append(rep('<', moves_right));
            append("]");

            // Now copy cell is zero, A restored.

            // Move to B[k]
            int curpos = acell+1; // after above we are back at acell+1 (zero)
            target = bcell;
            if(target < curpos) append(rep('<', curpos - target));
            else if(target > curpos) append(rep('>', target - curpos));
            // pointer at bcell

            // Copy B[bcell] -> bcell+1 and bcell+2 (zero bcell temporarily)
            append("[->+>+<<]");
            append(">>"); // at bcell+2
            append("[ - << + >> ]"); // restore B from bcell+2, leave copy at bcell+1
            append("<"); // at bcell+1 copy

            // transfer copy (bcell+1) -> mismatch (c17)
            moves_right = 17 - (bcell+1);
            append("[");
            append("-"); // decrement source
            append(rep('>', moves_right));
            append("+"); // add to mismatch
            append(rep('<', moves_right));
            append("]");

            // After this step mismatch cell c17 increased by Abit + Bbit.
            // For bits equal (0+0 or 1+1) c17 increases by 0 or 2.
            // For unequal bits, c17 increases by 1.
            // We'll detect later whether any per-bit contribution was odd.
            // Move pointer back to c16 (base) for next iteration
            // current pointer is at bcell+1; move to c16
            int curp = bcell+1;
            int dest = 16;
            if(dest < curp) append(rep('<', curp - dest));
            else if(dest > curp) append(rep('>', dest - curp));
            // pointer now at c16 ready for next k
        } // end k loop

        // After k loop, mismatch sum sits in c17.
        // We need to check whether any (A xor B) was 1 for any k.
        // If all A[k]==B[k], then each k contributed 0 or 2 -> c17 is even.
        // If any mismatch occurred, c17 will be odd. So we check parity c17%2.
        // To check parity: copy c17 to c18 (preserve c17), then subtract 2 repeatedly from c18 until 0/1 remains.
        // Move to c17
        append(">");
        // clear c18 (cell 18) to be safe
        append(">"); append("[-]"); // c18 = 0
        append("<"); // back to c17

        // copy c17 -> c18 and restore c17: [->+>+<<] >> [ - << + >> ] < (c17 preserved, c18 copy)
        append("[->+>+<<]"); // c17 -> c18 and c19 copies (c17=0)
        append(">>"); // at c19
        append("[ - << + >> ]"); // restore c17 from c19 (leaves c18 with copy)
        append("<"); // now at c18

        // reduce c18 by 2 until 0/1 remains:
        // while c18>0 { c18--; if c18>0 { c18--; } }  => leaves 0 or 1
        append("["); // outer while c18>0
        append("-"); // c18--
        append("["); // if still >0
        append("-"); // c18--
        append("]"); // end inner
        append("]"); // end outer
        // pointer at c18 and its value is parity (0 or 1)

        // If c18 == 0 -> even -> match at this position -> set c16 = 1 and skip remaining positions.
        // We test c18>0 or ==0 using the classic trick:
        // set c19 = 1, then subtract c18 from it: if c18==0 => c19 stays 1; if c18==1 => c19 becomes 0.
        // Then test c19's [ ] block.

        append(">"); // move to c19
        append("[-]"); append("+"); // c19 = 1
        append("<"); // back to c18

        // subtract c18 from c19 by looping over c18
        append("["); // while c18>0
        append("-"); // c18--
        append(">"); // to c19
        append("-"); // c19--
        append("<"); // back
        append("]");

        // now if c19 == 1 => c18 was 0 (match). if c19 == 0 => c18 was 1 (mismatch)
        append(">"); // at c19

        // if c19>0 -> set match flag c16 = 1
        append("["); // if c19>0
        append("<"); // move to c18 (just to be safe)
        append("<<"); // move to c16
        append("+"); // c16 = 1 (mark match)
        append(">>"); // back to c18/c19 area
        append("]");

        // restore pointer to c16 for check whether match flag set
        append("<<"); // now at c16

        // If match flag c16 is 1, we need to skip remaining positions.
        // We'll check c16 and if 1 then jump to output. We simulate 'if c16>0 goto output' using BF:
        // Move to c16, copy its value to c20 and use it as a conditional.
        append("["); // if c16>0
        // inside here we will clear remaining position-check work by quickly zeroing c17..c19
        // then jump (we'll simply proceed; since c16>0 we will avoid further pos loops by checking c16 at each pos start)
        append("]");

        // After this pos iteration, loop continues to next p. But at next p start,
        // we can check c16 and skip work if it is already 1. To do that we place at beginning of pos loop:
        // We'll implement this check by testing c16 at top of each p iteration:
        // (we will add it at top next iteration via generator structure)
        //
        // Before next p, we must clear c17,c18,c19 to zero to avoid accumulation across positions.
        append(">>"); // go to c18
        append("[-]"); // clear c18
        append(">"); append("[-]"); // clear c19
        append("<<<"); // back to c16
    } // end p loop

    // After checking all positions p, c16==1 if match found else 0.
    // Output '1' or '0' (+ newline).
    // Move to c20 to build the ascii char then output.
    // We'll use c20 to create ascii and output.

    // move to c20 (cells: 0.., c20 is reasonably far: we'll move from c16 -> c20)
    append(rep('>', 4)); // from c16 to c20
    append("[-]"); // clear c20

    // if c16 == 1: we want to output '1' (49)
    // We'll test c16 by subtracting it from helper cell c21=1; To do that, copy c16 value to c22 and test.
    // Simpler: move back to c16, if c16>0 set c20=49; else set c20=48.
    append(rep('<', 4)); // back to c16

    // if c16>0
    append("["); // enter if c16>0
    // set c20 = 49 and output
    append(rep('>', 4)); // to c20
    append(rep('+', 49)); // c20 = 49
    append("."); // output '1'
    append("[-]"); // clear c20
    // output newline
    append(rep('+', 10)); append("."); append("[-]"); // c20 reused: newline
    // clear c16 and helper cells for next line
    append(rep('<',4)); // back to c16
    append("[-]"); // clear c16
    append("]"); // end if

    // else case: when c16 == 0 -> print '0'
    // If c16 is zero the above [ ] didn't run. We'll test by incrementing c16 and running a block then restoring.
    append("+"); // c16 becomes 1 temporarily if it was 0 -> we can use [ ] to print '0'
    append("["); // now this runs only when original c16 was 0
    append(rep('>',4)); // to c20
    append(rep('+',48)); append("."); append("[-]"); // output '0'
    append(rep('+',10)); append("."); append("[-]"); // newline
    append(rep('<',4)); // back to c16
    append("-"); // restore c16 to 0
    append("]");

    // Finally clear A,B and temporaries cells 0..20 to prepare for next line.
    // Move pointer to cell 0 and zero cells 0..20
    append(rep('<', 16)); // from c16 back to c0
    for(int z=0; z<=20; z++){
        append("[-]");
        if(z<20) append(">");
    }
    // after clearing pointer at cell 20; move back to 0 for next line start
    append(rep('<',20));

    // That's our line block. We'll now produce 24 copies of it in the final BF program.
    string full;
    for(int t=0;t<24;t++){
        full += line;
    }

    // print out full BF program
    cout << full << endl;

    return 0;
}
