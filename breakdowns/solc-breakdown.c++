// 608060405234801561000f575f80fd5b506101438061001d5f395ff3fe608060405234801561000f575f80fd5b5060043610610034575f3560e01c8063cdfead2e14610038578063e026c01714610054575b5f80fd5b610052600480360381019061004d91906100ba565b610072565b005b61005c61007b565b60405161006991906100f4565b60405180910390f35b805f8190555050565b5f8054905090565b5f80fd5b5f819050919050565b61009981610087565b81146100a3575f80fd5b50565b5f813590506100b481610090565b92915050565b5f602082840312156100cf576100ce610083565b5b5f6100dc848285016100a6565b91505092915050565b6100ee81610087565b82525050565b5f6020820190506101075f8301846100e5565b9291505056fea2646970667358fe1220fefefefe62a8e6889a76fd12d6b9e7364d16aefe1211f170de2ce08e540beb4464736f6c63430008140033

// 1. Contract creation
// 2. Runtime code
// 3. Metadata

// 1. Contract Creation Code
// Free memory pointer
PUSH1 0x80
PUSH1 0x40
MSTORE

// What does this do?
// Checks to see if any value was sent with the contract creation call
// If so, it reverts else it jumps to a PC/JUMPDEST to continue execution
CALLVALUE               // -> [msg.value]
DUP1                    // -> [msg.value, msg.value]
ISZERO                  // -> [msg.value == 0, msg.value]]
PUSH2 0x000f            // -> [0x000f, msg.value == 0, msg.value]

// JUMPS to JUMPDEST at 0x000f if no value was sent (section to copy code to memory and return it on chain)
JUMPI                   // -> [msg.value]

// We only reach this part if value was sent
PUSH0                   // -> [0, msg.value]
DUP1                    // -> [0, 0, msg.value]
REVERT                  // -> []

// The copmiler would skip the above check if we had a constructor annotatated with 'payable'

// Jump destination for when no value is sent
// Sticks the code on chain
JUMPDEST                // -> [msg.value]
POP                     // -> []
PUSH2 0x0143            // -> [0x0143]
DUP1                    // -> [0x0143, 0x0143]
PUSH2 0x001d            // -> [0x001d, 0x0143, 0x0143]
PUSH0                   // -> [0, 0x001d, 0x0143, 0x0143]
CODECOPY                // -> [0x0143]                      Memory[0:0x0143] = Runtime Code[0x001d:0x0160]
PUSH0                   // -> [0, 0x0143] 
RETURN                  // -> []                            
INVALID                 // -> []

// 2. Runtime Code
// Free memory pointer
PUSH1 0x80              // -> [0x80]    
PUSH1 0x40              // -> [0x40, 0x80]
MSTORE                  // -> []

// Check for msg.value sent with call
CALLVALUE               // -> [msg.value]
DUP1                    // -> [msg.value, msg.value]
ISZERO
PUSH2 0x000f
JUMPI

// Jump to "continue!" if no value was sent

// If value was sent, revert
// Solidity has determined that we have no payable functions, hence it reverts on any value sent
PUSH0
DUP1
REVERT

// continue!
// Checks to see if the calldata is big enough to contain a function selector
// This is happenining because we do not have a fallback function defined so it expects us to call a function
JUMPDEST
POP
PUSH1 0x04
CALLDATASIZE
LT
PUSH2 0x0034
JUMPI
// calldata less than 4 bytes, jump to "revert_calldata!"


// Function dispatcher
PUSH0
CALLDATALOAD
PUSH1 0xe0
SHR
DUP1
PUSH4 0xcdfead2e
EQ
PUSH2 0x0038
JUMPI
DUP1
PUSH4 0xe026c017
EQ
PUSH2 0x0054
JUMPI

// revert_calldata! JUMPDEST
// Revert Jumpdest
JUMPDEST
PUSH0
DUP1
REVERT


JUMPDEST
PUSH2 0x0052
PUSH1 0x04
DUP1
CALLDATASIZE
SUB
DUP2
ADD
SWAP1
PUSH2 0x004d
SWAP2
SWAP1
PUSH2 0x00ba
JUMP
JUMPDEST
PUSH2 0x0072
JUMP
JUMPDEST
STOP
JUMPDEST
PUSH2 0x005c
PUSH2 0x007b
JUMP
JUMPDEST
PUSH1 0x40
MLOAD
PUSH2 0x0069
SWAP2
SWAP1
PUSH2 0x00f4
JUMP
JUMPDEST
PUSH1 0x40
MLOAD
DUP1
SWAP2
SUB
SWAP1
RETURN
JUMPDEST
DUP1
PUSH0
DUP2
SWAP1
SSTORE
POP
POP
JUMP
JUMPDEST
PUSH0
DUP1
SLOAD
SWAP1
POP
SWAP1
JUMP
JUMPDEST
PUSH0
DUP1
REVERT
JUMPDEST
PUSH0
DUP2
SWAP1
POP
SWAP2
SWAP1
POP
JUMP
JUMPDEST
PUSH2 0x0099
DUP2
PUSH2 0x0087
JUMP
JUMPDEST
DUP2
EQ
PUSH2 0x00a3
JUMPI
PUSH0
DUP1
REVERT
JUMPDEST
POP
JUMP
JUMPDEST
PUSH0
DUP2
CALLDATALOAD
SWAP1
POP
PUSH2 0x00b4
DUP2
PUSH2 0x0090
JUMP
JUMPDEST
SWAP3
SWAP2
POP
POP
JUMP
JUMPDEST
PUSH0
PUSH1 0x20
DUP3
DUP5
SUB
SLT
ISZERO
PUSH2 0x00cf
JUMPI
PUSH2 0x00ce
PUSH2 0x0083
JUMP
JUMPDEST
JUMPDEST
PUSH0
PUSH2 0x00dc
DUP5
DUP3
DUP6
ADD
PUSH2 0x00a6
JUMP
JUMPDEST
SWAP2
POP
POP
SWAP3
SWAP2
POP
POP
JUMP
JUMPDEST
PUSH2 0x00ee
DUP2
PUSH2 0x0087
JUMP
JUMPDEST
DUP3
MSTORE
POP
POP
JUMP
JUMPDEST
PUSH0
PUSH1 0x20
DUP3
ADD
SWAP1
POP
PUSH2 0x0107
PUSH0
DUP4
ADD
DUP5
PUSH2 0x00e5
JUMP
JUMPDEST
SWAP3
SWAP2
POP
POP
JUMP
INVALID
LOG2
PUSH5 0x6970667358
INVALID
SLT
KECCAK256
INVALID
INVALID
INVALID
INVALID
PUSH3 0xa8e688
SWAP11
PUSH23 0xfd12d6b9e7364d16aefe1211f170de2ce08e540beb4464
PUSH20 0x6f6c63430008140033