#!/usr/bin/env bats

make > /dev/null 2>&1

function setup {
    sudo insmod mod-trex.ko
}

function teardown {
    echo "Removing module"
    sudo rmmod mod-trex
}

@test "/dev/trex exists" {
    [ -e /dev/trex ]
}

@test "/dev/trex roars when you poke it" {
    run cat /dev/trex
    [ "$status" -eq 0 ]
    [ "$output" = "Rawr" ]
}

@test "/dev/trex eats data" {
    run echo "goat" > /dev/trex
    [ "$status" -eq 0 ]
    [ "$output" = "Omnomnom" ]
}
