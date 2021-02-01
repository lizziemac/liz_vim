var os = require('os');
var path = require('path');
var fs = require('fs');
var Program = require('commander');

var DelaneyBLE = require('../src/delaney.js');
var RavenBLE = require('../src/raven.js');

const rls = require('readline-sync')

/*************************************************************************/
/*                             CONFIG FILE                               */
/*************************************************************************/
let config = JSON.parse(fs.readFileSync(path.resolve(__dirname, "../config.json")));

/*************************************************************************/
/*                             BLE OBJECT                                */
/*************************************************************************/
let BLEObject = null;

/*************************************************************************/
/*                        COMMAND LINE PARSER                            */
/*************************************************************************/
Program
  .usage('-c <cmd> -n <scan-type>\n')
  .version('0.1.1')
  .option('-c, --CommandArg [Integer]', 'Select the command to run')
  .option('-T, --BLEScanType [Delaney/Raven]', 'Select the project type to scan for')
  .parse(process.argv)


if (!Program.BLEScanType)
{
    console.log('usage: -c <cmd> -n <scan-type>\n');
}
else if (Program.BLEScanType)
{
    switch (Program.BLEScanType)
    {
        case "Raven":
        {
            BLEObject = new RavenBLE();
            break;
        }
        case "Delaney":
        {
            BLEObject = new DelaneyBLE();
            break;
        }
        default:
        {
            console.log("No supported type chosen");
            process.exit();
        }
    }

    switch (isNaN(Program.CommandArg) || parseInt(Program.CommandArg))
    {
        case true: //is NaN
        case BLEObject.commands.DisplayMenu:
        {
            BLEObject.print_menu();
            break;
        }
        case BLEObject.commands.DisplayCmdInfo:
        {
            Program.help();
            break;
        }
        default:
        {
            console.log("Invalid Argument");
            process.exit();
        }
    }
}

console.log("Done");




