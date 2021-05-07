## Problem
Sussutu is a world-renowned magician. And recently, he was blessed with the power to remove EXACTLY ONE element from an array.<br/>

Given, an array A (index starting from 0) with N elements. Now, Sussutu CAN remove only that element which makes the sum of ALL the remaining elements exactly divisible by 7.<br/>

Throughout his life, Sussutu was so busy with magic that he could never get along with maths. Your task is to help Sussutu find the first array index of the smallest element he CAN remove.<br/>

## Input
The first line contains a single integer N.<br/>
Next line contains N space separated integers Ak , 0 < k < N.

## Output
Print a single line containing one integer, the first array index of the smallest element he CAN remove, and -1 if there is no such element that he can remove!

## Constraints:
1 <= N <= <code>10<sup>5</sup></code>
0 <= <code>A<sub>k</sub></code> <= <code>10<sup>9</sup></code>

###### Sample Input:
5
14 7 8 2 4
###### Sample Output:
1