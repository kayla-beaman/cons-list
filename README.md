# A Cons List Implementation for C++
## Description:
This is a linked-list implementation that is supposed to mirror how lists are made in Scheme. Lists are linkned together through "cons" pairs and items in the list are retrieved by calling any of the "car" variations (car, cadr, caddr, caddr, etc).

The Cons_List structure can contain multiple different types inside of it. Because this structure makes use of C++ templates, the declaration and description must be all in one header file :(