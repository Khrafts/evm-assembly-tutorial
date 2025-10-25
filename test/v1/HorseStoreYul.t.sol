// SPDX-License-Identifier: MIT
pragma solidity 0.8.20;

import {Base_TestV1} from "./Base_TestV1.t.sol";
import {HorseStoreYul} from "../../src/horseStoreV1/HorseStoreYul.sol";
import {IHorseStore} from "../../src/horseStoreV1/interface/IHorseStore.sol";

contract HorseStoreHuff is Base_TestV1 {

    string public constant HORSE_STORE_HUFF_LOCATION = "horseStoreV1/HorseStore";
    function setUp() public override {
        horseStore = IHorseStore(address(new HorseStoreYul()));
    }
}