# STM32F401RE Template
This is not a working workspace, some setups are needed. 

1. Copy this file to another directory. 
2. Run the following commands
```zsh
$ chmod 775 ./setup.sh && ./setup.sh

# If the above commands fail, then run this
    $ git init          # Initialise Git 
    $ git submodule add https://github.com/libopencm3/libopencm3    # add libopencm3

    $ cd libopencm3
    $ make              # Precompile libopencm3
# endif

$ cd ../app
$ make              # Compile blinky
```

The 2 instructions above are only needed once. Consequently when you clone this particular project from github, you can just run
```bash
$ git clone <URL>
$ git submodule init
$ git submodule update

$ cd libopencm3
$ make

$ cd ../app
$ make
```