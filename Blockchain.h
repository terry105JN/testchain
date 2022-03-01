#ifndef TESTCHAIN_BLOCKCHAIN_H
#define TESTCHAIN_BLOCKCHAIN_H

// Imports
#include <cstdint>
#include <vector>
#include "Block.h"

// Set Namespace
using namespace std;

// Class: Blockchain
class Blockchain
{
public:
    // Constrictor: No Parameters
    Blockchain();

    // Getter Methods
    void AddBlock(Block bNew);

private:
    // Private Variables
    uint32_t _nDifficulty;
    vector<Block> _vChain;

    // Private Methods
    Block _GetLastBlock() const;
};

#endif