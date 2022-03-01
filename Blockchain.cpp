// Imports
#include "Blockchain.h"

// Implementation: Blockchain Constructor
Blockchain::Blockchain()
{
    // Initialize Values
    _vChain.__emplace_back(Block(0, "Genesis Block"));
    _nDifficulty = 4; // Set Difficulty
}

// Mutator: Add Block
void Blockchain::AddBlock(Block bNew)
{
    // Set Previous Hash; Mine Block; Push to Chain
    bNew.sPrevHash = _GetLastBlock().GetHash();
    bNew.MineBlock(_nDifficulty);
    _vChain.push_back(bNew);
}

// Accessor: Last Block Found
Block Blockchain::_GetLastBlock() const
{
    return _vChain.back();
}