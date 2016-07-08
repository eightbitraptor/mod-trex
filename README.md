# mod-trex

    sudo dnf install gcc kernel-devel
    make
    sudo insmod mod-trex.ko
    dmesg # to see the output


## running tests

Tests are written using bats `sudo dnf install bats`. They'll need your `sudo`
password as the setup process runs `make` and then inserts the module into the
kernel, and the teardown removes the module from the kernel

	bats tests.bats
