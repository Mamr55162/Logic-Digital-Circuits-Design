#pragma once
#include <iostream>
#include <vector>
#include <bitset>
using namespace std;
#ifndef COMBINATIONAL_CIRCUITS_H
#define COMBINATIONAL_CIRCUITS_H


class Wire
{
private:
   bool value = false;

public:
   void set(bool v) { value = v; }
   bool get() const { return value; }
};

//Multiple Indicators class.
class Indicator
{
public:
   //Use LED as indicator for HIGH (1) and LOW (0) outputs.
   static void LED(bool val)
   {
      if (val == true)
         cout << "LED is ON\n";
      else
         cout << "LED is OFF\n";
   }
   //Print the binary value(s).
   static void Binary(bool val)
   {
      cout << val;
   }
   static void BinaryVector(const vector<bool>& bits)
   {
      for (bool b : bits)
         cout << b;

      cout << '\n';
   }
   //Detect whether a wire is HIGH (1) or LOW (0).
   static void Probe(bool val)
   {
      cout << (val ? "HIGH" : "LOW") << endl;
   }
   //Print decimal equivalent of BCD.
   static void Decimal(const bitset<4>& bcd)
   {
      cout << bcd.to_ulong() << endl;
   }
   //Bus Monitor.
   static void Bus(const bitset<4>& bus)
   {
      cout << "BUS: " << bus << endl;
   }
};

//Print two-input gates truth tables.
class TruthTable
{
public:
   static void ANDTruthTable()
   {
      cout << "A  B | F\n";
      cout << "0  0 | 0\n";
      cout << "0  1 | 0\n";
      cout << "1  0 | 0\n";
      cout << "1  1 | 1\n";
   }
   static void ORTruthTable()
   {
      cout << "A  B | F\n";
      cout << "0  0 | 0\n";
      cout << "0  1 | 1\n";
      cout << "1  0 | 1\n";
      cout << "1  1 | 1\n";
   }
   static void NANDTruthTable()
   {
      cout << "A  B | F\n";
      cout << "0  0 | 1\n";
      cout << "0  1 | 1\n";
      cout << "1  0 | 1\n";
      cout << "1  1 | 0\n";
   }
   static void NORTruthTable()
   {
      cout << "A  B | F\n";
      cout << "0  0 | 1\n";
      cout << "0  1 | 0\n";
      cout << "1  0 | 0\n";
      cout << "1  1 | 0\n";
   }
   static void XORTruthTable()
   {
      cout << "A  B | F\n";
      cout << "0  0 | 0\n";
      cout << "0  1 | 1\n";
      cout << "1  0 | 1\n";
      cout << "1  1 | 0\n";
   }
   static void XNORTruthTable()
   {
      cout << "A  B | F\n";
      cout << "0  0 | 1\n";
      cout << "0  1 | 0\n";
      cout << "1  0 | 0\n";
      cout << "1  1 | 1\n";
   }
   static void NOTTruthTable()
   {
      cout << "A | F\n";
      cout << "0 | 1\n";
      cout << "1 | 0\n";
   }
   static void Tri_stateTruthTable()
   {
      cout << "EN  A | F\n";
      cout << "0  0 | Hi-Z\n";
      cout << "0  1 | Hi-z\n";
      cout << "1  0 | 0\n";
      cout << "1  1 | 1\n";
   }
};


//Universal gate NAND implementation.
/*
class NAND
{
public:
  static bool compute(bool A, bool B)
   {
      return !(A & B);
   }
};
*/
//Implement NOT, OR, AND, NOR, XOR, XNOR, Tri-state gates using NAND gate only.
class Gates
{
public:
   static bool NAND(bool A, bool B)
   {
      return !(A & B);
   }
   static bool NOT(bool A)
   {
      return NAND(A, A);
   }
   static bool OR(bool A, bool B)
   {
      return NAND(NAND(A,A), NAND(B, B));
   }
   static bool AND(bool A, bool B)
   {
      return NAND(NAND(A, B), NAND(A, B));
   }
   static bool NOR(bool A, bool B)
   {
      return NAND(NAND(NAND(A, A), NAND(B, B)),
                           NAND(NAND(A, A), NAND(B, B)));
   }
   static bool XOR(bool A, bool B)
   {
      bool x = NAND(A, B);
      bool y = NAND(A, x);
      bool z = NAND(B, x);
      return NAND(y, z);
   }
   static bool XNOR(bool A, bool B)
   {
      bool x = NAND(A, B);
      bool y = NAND(A, x);
      bool z = NAND(B, x);
      bool out_invert = NAND(y, z);
      return NAND(out_invert, out_invert);
   }
  enum TriState
    {
        LOW = 0,
        HIGH = 1,
        HIGH_Z
    };

    static TriState Tri_state(bool A, bool EN)
    {
        if (!EN)
            return HIGH_Z;

        return A ? HIGH : LOW;
    }
};


class combinational_circuits
{

public:
   static vector<bool> Half_Adder(bool A, bool B);
   static vector<bool> Full_Adder(bool A, bool B, bool C);
   static vector<bool> _74HC283_(bitset<4> A, bitset<4> B, bool C_in, bool stat);
   static bool Identity_Comparator(bitset<4> A, bitset<4> B);
   static vector<bool> _74HC85_(bitset<4> A, bitset<4> B, bool eq = 0b1, bool larger = 0b0, bool smaller = 0b0);
   static bool MUX_4_to_1(bitset<4> A, bool S0, bool S1);
   static vector<bool> _74HC151_(bitset<8> A, bool S0, bool S1, bool S2);
   static vector<bool> Decoder_2_to_4(bool A, bool B);
   static vector<bool> _74HC154_(bool A0, bool A1, bool A2, bool A3, bool EN);
   static bool Decoder_to_MUX(bool S1, bool S0, bool I0, bool I1, bool I2, bool I3);
   static vector<bool> _74HC42_(bool A0, bool A1, bool A2, bool A3);
   static vector<bool> BCD_to_7_Segment(bool A0, bool A1, bool A2, bool A3, bool decimal);
};


#endif //COMBINATIONAL_CIRCUITS_H
