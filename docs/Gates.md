# Gates class
## Overview
This class focuses on implementing every logic gate using a universal logic gate NAND.

<img width="340" height="188" alt="image" src="https://github.com/user-attachments/assets/02bb158c-6ffc-4a64-97b5-2b286b41ffe7" />


***NAND Gate***

| A | B | Y |
| - | - | - |
| 0 | 0 | 1 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

Y = (AB)' = A' + B'

## Code Walkthrough 
Implementation of NAND gate is used in another class:
```cpp
static bool compute(bool A, bool B)
   {
      return !(A & B);
   }
```
It uses the bitwise AND **&** with a NOT operator **!** at the parentheses to inverse the AND operation.
For the Gates class, start by the code order:
* NOT Gate: implemented using a NAND with its two inputs tied together, in the following code snippet
```cpp
static bool NOT(bool A)
 {
    return NAND::compute(A, A);
 }
```
<img width="183" height="43" alt="image" src="https://github.com/user-attachments/assets/9f2f22c9-5ca4-4b7c-a0ec-abeabbc5335c" />

* OR Gate: implemented using three NAND gates, two for inverting inputs working as NOT gates, and a usual one, so when you apply De Morgan's law the product becomes sum and the complements cancel
```cpp
static bool OR(bool A, bool B)
   {
      return NAND::compute(NAND::compute(A,A), NAND::compute(B, B));
   }
```

<img width="248" height="77" alt="image" src="https://github.com/user-attachments/assets/2e74a040-525d-44e0-8ea3-cba50a5484dc" />

