#!/usr/bin/env bats

function setup {
	echo "building module"
	make
	echo "inserting module"
	sudo insmod mod-trex.ko
}

function teardown {
	echo "Removing module"
	sudo rmmod mod-trex
}

@test "/dev/trex exists" {
	[ -e /dev/trex ]
}
