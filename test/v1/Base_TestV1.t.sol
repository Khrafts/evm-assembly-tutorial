// SPDX-License-Identifier: MIT
pragma solidity 0.8.20;

import {HorseStore} from "../../src/horseStoreV1/HorseStore.sol";
import {Test, console2} from "forge-std/Test.sol";

abstract contract Base_TestV1 is Test {
    string public constant horseStoreLocation = "horseStoreV1/HorseStore";
    HorseStore horseStore;

    function setUp() public virtual {
        horseStore = new HorseStore();
    }

    function testReadValue() public {
        uint256 initialValue = horseStore.readNumberOfHorses();
        assertEq(initialValue, 0);
    }

    function testWriteValue(uint256 newValue) public {
        horseStore.updateHorseNumber(newValue);
        uint256 readValue = horseStore.readNumberOfHorses();
        assertEq(readValue, newValue);
    }
}