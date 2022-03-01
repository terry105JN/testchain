#ifndef TESTCHAIN_BLOCK_H
#define TESTCHAIN_BLOCK_H

// Imports
#include <cstdint>
#include <iostream>

// Set Namespace
using namespace std;

// Class: Block
class Block
{
public:
    // Constructor: Three Parameters
    Block(uint32_t nIndexIn, const string &sDataIn);

    // Getter Methods
    string sPrevHash;
    string GetHash();

    // Setter Methods
    void MineBlock(uint32_t nDifficulty);

private:
    // Private Variables
    uint32_t _nIndex;
    int64_t _nNonce;
    string _sData;
    string _sHash;
    time_t _tTime;

    // Private Methods
    string _CalculateHash() const;
};

#endif