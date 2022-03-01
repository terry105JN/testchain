// Imports
#include <sstream>
#include "Block.h"
#include "sha256/sha256.h" // License in directory

// Implementation: Block Constructor
Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
    // Initialize values
    _nNonce = -1;
    _tTime = time(nullptr); // Current time
}

// Accessor: Block Hash
string Block::GetHash()
{
    return _sHash;
}

// Mutator: Mine Block
void Block::MineBlock(uint32_t nDifficulty)
{
    // Set Difficulty
    char cstr[nDifficulty + 1];
    for (uint32_t i = 0; i < nDifficulty; ++i)
    {
        cstr[i] = '0';
    }
    cstr[nDifficulty] = '\0';
    string str(cstr);

    // Proof of Work (PoW) Process
    do
    {
        _nNonce++;
        _sHash = _CalculateHash();
    } while (_sHash.substr(0, nDifficulty) != str);

    // Output: Valid Hash Found
    cout << "Block mined: " << _sHash << endl;
}

// Calculate: Block Hash
inline string Block::_CalculateHash() const
{
    // Convert to Stringstream
    stringstream ss;
    ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

    // Utilize SHA256 Method
    return sha256(ss.str());
}