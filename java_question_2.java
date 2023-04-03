/*Nanda Child Care is the hospital where a system is required to maintain the record of births and issuing the birth certificate as a child is born. Birth certificate can only be issued if a new child is born, birth certificate cannot be issued before birth or even during the delivery.

Input Format

First line will contain one integer value i.e. 0 representing birth of child.
Second line will contain one integer value i.e.1 representing issued birth certificate.

Constraints

First line must contain 0 i.e. print without birth no certificate
Second line must contain 1 if anything else, then print invalid input

Output Format

Certificate Issued/Not Eligible

Sample Input 0

0
1
Sample Output 0

Certificate Issued
*/


import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int birth = s.nextInt();
        int certi = s.nextInt();
        if(birth != 0)
            System.out.println("without birth no certificate");
        else if(certi != 1)
            System.out.println("invalid input");
        else
            System.out.println("Certificate Issued");
    }
}
