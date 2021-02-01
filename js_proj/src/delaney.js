var BLE = require('../src/intermediary.js');

//Delaney BLE

const DelaneyCommands = Object.freeze({
    "DisplayMenu":0,
    "DisplayCmdInfo":1,
    "Commissioning":2,
    "Access":3,
    "AddUser":4,
    "RemoveUser":5,
    "BlockUser":6,
    "GetAudits":7,
    "MasterKeyAccess":8,
    "InitiateOTA":9,
    "GetTime":10,
    "SetTime":11,
    "SetName":12,
    "VersionGet":13,
    "Resync":14,
    "Recalibrate":15,
    "SetTimezone":16,
    "SetAdvertInterval":17
});

const DelaneyUUIDs = Object.freeze({
     "ServiceShortID":      'e2b7',
     "ServiceUUID":         '3438e2b7e2780aa6234d3a43da5f52d1',
     "DataPayloadCharUUID": '3438e2b9e2780aa6234d3a43da5f52d1',
     "DataLenCharUUID":     '3438e2bae2780aa6234d3a43da5f52d1',
     "NonceCharUUID":       '3438e2bbe2780aa6234d3a43da5f52d1'
});


class DelaneyBLE extends BLE {
    constructor(name = "Delaney", commands = DelaneyCommands, uuids = DelaneyUUIDs) {
        super(name, commands, uuids);
    }


    print_menu() {
        super.print_menu("DELANEY TEST");
    }

}

module.exports = DelaneyBLE;
