#!/usr/bin/env perl

# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
# * This source file is part of SableVM.                            *
# *                                                                 *
# * See the file "LICENSE" for the copyright information and for    *
# * the terms and conditions for copying, distribution and          *
# * modification of this source file.                               *
# * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

# Use this to initialize inlineability informations for another architecture.
# Usage: ./addarch.pl ./inlineability.list >./inlineability.list-new

while (<>) { s/,([^,]{3,5}),\s*$/,$1,    ,\n/; print ; }
