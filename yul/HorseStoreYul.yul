object "HorseStoreYul" {
    code {
        // Contract deployment 
        datacopy(0, dataoffset("runtime"), datasize("runtime"))
        return(0, datasize("runtime"))
    }

    object "runtime" {
        code {
            // Function dispatcher
            switch selector()
            // updateHorseNumber(uint256)
            case 0xcdfead2e {
                storeNumber(decodeAsUint(0))
            }
            // readNumberOfHorses()
            case 0xe026c017 {
                let v := sload(0)
                returnUint(v)
            }

            default {
                revert(0, 0)
            }

            function storeNumber(newNumber) {
                sstore(0, newNumber)
            }

            function selector() -> s {
                s := shr(0xe0, calldataload(0))
            }

            function decodeAsUint(offset) -> value {
                let posInCallData := add(4, mul(offset, 0x20))
                if lt(calldatasize(), add(posInCallData, 0x20)) {
                    revert(0, 0)
                }
                value := calldataload(posInCallData)
            }

            function returnUint(v) {
                mstore(0, v)
                return(0, 0x20)
            }
        }
    }
}