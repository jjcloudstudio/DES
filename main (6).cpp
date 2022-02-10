#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <sstream>
#include <string>
#include <bitset>
#include <map>
#include <math.h>
using namespace std;

//this function can be used to convert hexadecimal value
string hexadecimalAsBinaryValue(string inputOfStringValue) {
    //here string to the binary string value
    string binaryAsOutputOfStringValue;
    map<char, string> mapCharacterKeyValue;
    mapCharacterKeyValue['0'] = "0000";
    mapCharacterKeyValue['1'] = "0001";
    mapCharacterKeyValue['2'] = "0010";
    mapCharacterKeyValue['3'] = "0011";
    mapCharacterKeyValue['4'] = "0100";
    mapCharacterKeyValue['5'] = "0101";
    mapCharacterKeyValue['6'] = "0110";
    mapCharacterKeyValue['7'] = "0111";
    mapCharacterKeyValue['8'] = "1000";
    mapCharacterKeyValue['9'] = "1001";
    mapCharacterKeyValue['A'] = "1010";
    mapCharacterKeyValue['B'] = "1011";
    mapCharacterKeyValue['C'] = "1100";
    mapCharacterKeyValue['D'] = "1101";
    mapCharacterKeyValue['E'] = "1110";
    mapCharacterKeyValue['F'] = "1111";

    for (int i = 0; i < inputOfStringValue.size(); i++) {
        binaryAsOutputOfStringValue += mapCharacterKeyValue[inputOfStringValue[i]];
    }
    return binaryAsOutputOfStringValue;
}

//this function can be used to convert binary
//string to a hexadecimal string
string binaryAsHexadecimal(string inputOfStringValue) {
    string hexadecimalAsOPStringValue;
    map<string, string> mapCharacterKeyValue;
    mapCharacterKeyValue["0000"] = "0";
    mapCharacterKeyValue["0001"] = "1";
    mapCharacterKeyValue["0010"] = "2";
    mapCharacterKeyValue["0011"] = "3";
    mapCharacterKeyValue["0100"] = "4";
    mapCharacterKeyValue["0101"] = "5";
    mapCharacterKeyValue["0110"] = "6";
    mapCharacterKeyValue["0111"] = "7";
    mapCharacterKeyValue["1000"] = "8";
    mapCharacterKeyValue["1001"] = "9";
    mapCharacterKeyValue["1010"] = "A";
    mapCharacterKeyValue["1011"] = "B";
    mapCharacterKeyValue["1100"] = "C";
    mapCharacterKeyValue["1101"] = "D";
    mapCharacterKeyValue["1110"] = "E";
    mapCharacterKeyValue["1111"] = "F";
    for (int i = 0; i < inputOfStringValue.size(); i += 4) {
        string c = "";
        c += inputOfStringValue[i];
        c += inputOfStringValue[i + 1];
        c += inputOfStringValue[i + 2];
        c += inputOfStringValue[i + 3];
        hexadecimalAsOPStringValue += mapCharacterKeyValue[c];
    }
    return hexadecimalAsOPStringValue;
}

string stringAsBinaryValue(string inputOfStringValue) {
    string binaryAndString = "";
    for(int i = 0; i < inputOfStringValue.size(); i++) {
        binaryAndString += bitset<8>(inputOfStringValue[i]).to_string();
    }
    return binaryAndString;
}

string binary2AsciiValue(string inputOfStringValue) {
    string ASCIIasString;
    stringstream sstream(inputOfStringValue);
    for(int i = 0; i < inputOfStringValue.size()/ 8; i++) {
            bitset<8> bits;
            sstream >> bits;
            char c = char(bits.to_ulong());
            ASCIIasString += c;
        }
    return ASCIIasString;
}

//this function will be reused for performing various permutations
//
string permuteFunVal(string data, int* pTable, int size)
{
    string outputKey = "";
    for (int i = 0; i < size; i++) {
        outputKey += data[pTable[i] - 1];
    }
    return outputKey;
}

string leftShift(string data, int numberOfShifts){
    string s = "";
    for (int i = 0; i < numberOfShifts; i++) {
        for (int j = 1; j < 28; j++) {
            s += data[j];
        }
        s += data[0];
        data = s;
        s = "";
    }
    return data;
}
string xorFunction(string s1, string s2){
    string x = "";
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] == s2[i]) {
            x += "0";
        }
        else {
            x += "1";
        }
    }
    return x;
}
string desEncryption(string plaintext,vector<string> keys){
    string cipher;
    string left;
    string right;
    string textjoint;
    int initialPermutTableVal[64] = { 58, 50, 42, 34, 26, 18, 10, 2,
                                 60, 52, 44, 36, 28, 20, 12, 4,
                                 62, 54, 46, 38, 30, 22, 14, 6,
                                 64, 56, 48, 40, 32, 24, 16, 8,
                                 57, 49, 41, 33, 25, 17, 9, 1,
                                 59, 51, 43, 35, 27, 19, 11, 3,
                                 61, 53, 45, 37, 29, 21, 13, 5,
                                 63, 55, 47, 39, 31, 23, 15, 7 };
    int DBTableExp[48] = { 32, 1, 2, 3, 4, 5, 4, 5,
                          6, 7, 8, 9, 8, 9, 10, 11,
                          12, 13, 12, 13, 14, 15, 16, 17,
                          16, 17, 18, 19, 20, 21, 20, 21,
                          22, 23, 24, 25, 24, 25, 26, 27,
                          28, 29, 28, 29, 30, 31, 32, 1 };
    int sbox[8][4][16] = { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                          0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                          4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                          15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
                        { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                          3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                          0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                          13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

                        { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                          13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                          13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                          1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
                        { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                          13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                          10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                          3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
                        { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                          14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                          4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                          11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
                        { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                          10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                          9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                          4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
                        { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                          13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                          1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                          6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
                        { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                          1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                          7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                          2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };
    int Permutation32Table[32] = { 16, 7, 20, 21,
                        29, 12, 28, 17,
                        1, 15, 23, 26,
                        5, 18, 31, 10,
                        2, 8, 24, 14,
                        32, 27, 3, 9,
                        19, 13, 30, 6,
                        22, 11, 4, 25 };
    int finalPermutationTable[64] = { 40, 8, 48, 16, 56, 24, 64, 32,
                               39, 7, 47, 15, 55, 23, 63, 31,
                               38, 6, 46, 14, 54, 22, 62, 30,
                               37, 5, 45, 13, 53, 21, 61, 29,
                               36, 4, 44, 12, 52, 20, 60, 28,
                               35, 3, 43, 11, 51, 19, 59, 27,
                               34, 2, 42, 10, 50, 18, 58, 26,
                               33, 1, 41, 9, 49, 17, 57, 25 };

    plaintext = permuteFunVal(plaintext, initialPermutTableVal, 64);
    left = plaintext.substr(0,32);
    right = plaintext.substr(32,32);
    for (int i = 0; i < 16; i++) {
        string rExpand = permuteFunVal(right, DBTableExp, 48);
        string x = xorFunction(keys[i], rExpand);
        string box = "";
        for (int i = 0; i < 8; i++) {
            int row = 2 * int(x[i * 6] - '0') + int(x[i * 6 + 5] - '0');
            int col = 8 * int(x[i * 6 + 1] - '0') + 4 * int(x[i * 6 + 2] - '0') + 2 * int(x[i * 6 + 3] - '0') + int(x[i * 6 + 4] - '0');
            int val = sbox[i][row][col];
            box += char(val / 8 + '0');
            val = val % 8;
            box += char(val / 4 + '0');
            val = val % 4;
            box += char(val / 2 + '0');
            val = val % 2;
            box += char(val + '0');
        }
        box = permuteFunVal(box, Permutation32Table, 32);
        // here xorFunction is the leftpart & sboxes
        x = xorFunction(box, left);
        left = x;
        if (i != 15) {
            swap(left, right);
        }
    }
    textjoint = left + right;
    cipher = binaryAsHexadecimal(permuteFunVal(textjoint, finalPermutationTable, 64));
    return cipher;
}

// here we run all the progg. and this controls the flow
int main(){
    int inputValueOfUser;
    //char inputOfStringValue[8];
    string inputOfStringValue, cypherValueText;
    string plainTextbase2, plainTextbase10;
    string keyBase16;
    string keyBase2;
    string l_Key, r_Key, combinedKey, compressedKey;
    vector <string> round_Keys;
    // will be used for left circular shift
    int circularShiftTable[16] = { 1, 1, 2, 2,
                            2, 2, 2, 2,
                            1, 2, 2, 2,
                            2, 2, 2, 1 };

    // will be used for data contraction
    int permutedChoiceTwoTable[48] = { 14, 17, 11, 24, 1, 5,
                        3, 28, 15, 6, 21, 10,
                        23, 19, 12, 4, 26, 8,
                        16, 7, 27, 20, 13, 2,
                        41, 52, 31, 37, 47, 55,
                        30, 40, 51, 45, 33, 48,
                        44, 49, 39, 56, 34, 53,
                        46, 42, 50, 36, 29, 32 };
    int permutedChoiceOneTable[56] = { 57, 49, 41, 33, 25, 17, 9,
        1, 58, 50, 42, 34, 26, 18,
        10, 2, 59, 51, 43, 35, 27,
        19, 11, 3, 60, 52, 44, 36,
        63, 55, 47, 39, 31, 23, 15,
        7, 62, 54, 46, 38, 30, 22,
        14, 6, 61, 53, 45, 37, 29,
        21, 13, 5, 28, 20, 12, 4 };
    cout<<"How can I help you? "<<endl;
    cout<<"(a). for DES encryption, enter 1 "<<endl;
    cout<<"(b). for DES Decryption, enter 2 "<<endl;
    cin>>inputValueOfUser;

    //here we do encryption of value
    if(inputValueOfUser == 1){
        //showing comments in here
        cout<<endl<<"Input 8 character string value here "<<endl;
        cin.ignore();
        //taking input of complete line in here
        getline(cin, inputOfStringValue);
        plainTextbase2 = stringAsBinaryValue(inputOfStringValue);
        cout<<"\nInput Hexadecimal Key Value here ";
        cout<<"\nThis is 16 characters long value "<<endl;
        cin>>keyBase16;
        keyBase2 = hexadecimalAsBinaryValue(keyBase16);
        //table is used to remove the parity bits
        keyBase2 = permuteFunVal(keyBase2, permutedChoiceOneTable, 56);
        l_Key = keyBase2.substr(0, 28);
        r_Key = keyBase2.substr(28, 28);
        for (int i = 0; i < 16; i++) {
                l_Key = leftShift(l_Key, circularShiftTable[i]);
                r_Key = leftShift(r_Key, circularShiftTable[i]);

                // Making them together here
                combinedKey = l_Key + r_Key;

                // Compression of key is done
                compressedKey = permuteFunVal(combinedKey, permutedChoiceTwoTable, 48);

                round_Keys.push_back(compressedKey);
            }
            cout << "Encryption is completed: "<< endl;
            cypherValueText = desEncryption(plainTextbase2, round_Keys);
            cout << "Cipher Text Value: " << cypherValueText << endl;

    }else if(inputValueOfUser == 2) {
        //here we decrypt the value in this part
        cout << "input the ciphertext value here";
        cin >> cypherValueText;
        cout<<"input the 16 digit DES key in hexadecimal";
        cin >> keyBase16;
        plainTextbase2 = hexadecimalAsBinaryValue(cypherValueText);
        keyBase2 = hexadecimalAsBinaryValue(keyBase16);
        //table is used to remove the parity bits in here
        keyBase2 = permuteFunVal(keyBase2, permutedChoiceOneTable, 56);
        l_Key = keyBase2.substr(0, 28);
        r_Key = keyBase2.substr(28, 28);
        for (int i = 0; i < 16; i++) {
                l_Key = leftShift(l_Key, circularShiftTable[i]);
                r_Key = leftShift(r_Key, circularShiftTable[i]);

                // making them together in this part
                combinedKey = l_Key + r_Key;
                compressedKey = permuteFunVal(combinedKey, permutedChoiceTwoTable, 48);

                round_Keys.push_back(compressedKey);
            }
        reverse(round_Keys.begin(), round_Keys.end());
            cout << "Decryption Successful!"<< endl;
            cypherValueText = desEncryption(plainTextbase2, round_Keys);
        cout<<"cipher before conversion\n" << cypherValueText<<endl;
        plainTextbase10 = binary2AsciiValue(hexadecimalAsBinaryValue(cypherValueText));
        cout << "Plain Text: \n" << plainTextbase10 << endl;

    }

    else {
        cout<<"Not the right input, try again? "<< endl;
    }
    return 0;
}