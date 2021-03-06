Title: Synchronisation

Description:

A simple application that demonstates basic sanity of the microkernel.
Two tasks (A and B) take turns printing a greeting message to the console,
and use sleep requests and semaphores to control the rate at which messages
are generated. This demonstrates that microkernel scheduling, communication,
and timing are operating correctly.

--------------------------------------------------------------------------------

Building and Running Project:

This microkernel project outputs to the console.  It can be built and executed
on QEMU as follows:

    make qemu

--------------------------------------------------------------------------------

Troubleshooting:

Problems caused by out-dated project information can be addressed by
issuing one of the following commands then rebuilding the project:

    make clean          # discard results of previous builds
                        # but keep existing configuration info
or
    make pristine       # discard results of previous builds
                        # and restore pre-defined configuration info

--------------------------------------------------------------------------------

Sample Output:

taskA: Hello World!
taskB: Hello World!
taskA: Hello World!
taskB: Hello World!
taskA: Hello World!
taskB: Hello World!
taskA: Hello World!
taskB: Hello World!
taskA: Hello World!
taskB: Hello World!

<repeats endlessly>
