class BLE {

    //TODO: perhaps standardize/force commands to have 
    // "DisplayMenu":0,
    // "DisplayCmdInfo":1,

    constructor(name, commands, uuids)
    {
        this.name = name;
        this.commands = commands;
        this.uuids = uuids;
    }

    print_menu(header)
    {
        this.header = header;

        console.log("\n\t%s", this.header);
        for (var key in this.commands)
        {
            var obj = this.commands[key];
            console.log("\t\t%d)\t%s", obj+1, key);
        }
        console.log("\n");
    }

    commission()
    {
    }

    access()
    {
    }

    add_user()
    {
    }

    remove_user()
    {
    }

    block_user()
    {
        this.remove_user();
    }

    get_audits()
    {
    }

    master_key_audits()
    {
    }

    initiate_ota()
    {
    }

    get_time()
    {
    }

    set_time()
    {
    }

    set_name()
    {
    }

    version_get()
    {
    }

    resync()
    {
    }

    recalibrate()
    {
    }

    set_timezone()
    {
    }

    set_advertising_interval()
    {
    }
}

module.exports = BLE;
