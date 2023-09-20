#ifndef msg_h
#define msg_h

/*

Specifications:

We want that the parameters passed to SID() (Source ID) be not
included in the object files.  Instead, they should be entered into a
database, and the SID() macro should be replaced by or expand to a
string containing a reference ID, a key into that database for
retrieval by the authors of the program, when reported by the users
(bug reports).

The parameters considered to this SID() macro can include the
following symbols:

- at macroexpansion-time:

    - __FILE__ (string)
    - __LINE__ (integer)
    - __DATE__ (string)
    - __TIME__ (string)

- at compilation-time:

    - __func__ (string)
    - __FUNCTION__ (string)
    - __PRETTY_FUNCTION__ (string)

Here lies the first difficulty: __func__ is only defined in the
compiler while compiling.  So we won't be able to perform this
processing merely at pre-processing time (macroexpansion-time).

The second difficulty is that this SID() macro will be typically
used in other macros, that need to be expanded so that the symbols
such as __FILE__ and __LINE__ are replaced by their values at the
right point in the source.

Note that __FILE__ and __LINE__ are determined from processing the
#line directive, in addition to the actual source file and line counting. 


This means that implementing the required functionality will involve a
(partial) pre-processor, and a (very partial) C scanner, to identify
the function names.

The actual format of source IDs will be a parameter of the tool.

*/

#define SID(...) /* provide a source reference ID: */"[SID:000000]"

#endif

