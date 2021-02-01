//Raven BLE
var BLE = require('../src/intermediary.js');

const RavenCommands = Object.freeze({
    "DisplayMenu":0,
    "DisplayCmdInfo":1,
    "Commissioning":2,
    "Access":3,
    "AddUser":4,
    "RemoveUser":5,
    "BlockUser":6,
    "GetAudits":7,
    "InitiateOTA":8,
    "GetTime":9,
    "SetTime":10,
    "SetName":11,
    "VersionGet":12,
    "SetTimezone":13,
    "SetAdvertInterval":14
});

const RavenUUIDs = Object.freeze({
     "ServiceShortID":  'fa42',
     "ServiceUUID":         '2117fa4257d241138b64a6a10fe863a0',
     "DataPayloadCharUUID": '2117fa4357d241138b64a6a10fe863a0',
     "DataLenCharUUID":     '2117fa4457d241138b64a6a10fe863a0',
     "NonceCharUUID":       '2117fa4557d241138b64a6a10fe863a0' //this is ACK/NACK
});


class RavenBLE extends BLE {
  constructor(name = "Raven", commands = RavenCommands, uuids = RavenUUIDs) {
    super(name, commands, uuids);
  }

  print_menu() {
      console.log("Printing");
      super.print_menu("RAVEN TEST");
  }
}

module.exports = RavenBLE;
