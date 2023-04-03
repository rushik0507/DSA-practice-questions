/*balance if less than 1000 than customer can not withdraw any amount and show massage "insufficient balance".
if customer try to withdraw the amount more than balance than customer can not withdraw any amount and show massage "over withdraw not allow"

Input Format

Line 1: Read balance Line 2: Read withdraw amount

Constraints

balance > 1000

Output Format

Display the current balance after withdraw

Sample Input 0

5000
2000
Sample Output 0

3000
Sample Input 1

500
300
Sample Output 1

insufficient balance
*/


import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
       Scanner cin = new Scanner(System.in);
        int a = cin.nextInt();
        int b = cin.nextInt();
        if ( a < 1000) System.out.println("insufficient balance");
        else if (  a < b )  System.out.println( "over withdraw not allow");
        else  System.out.println((a-b));
        
    }
}
