#*******************************************************************************
# Copyright (c) Judson James
# 
# While this is not the "cleanest" way to install it, it does in fact work.
# 
# What this does:
#   - Clones the Google Styleguide Repository
#   - Appends to the bashrc the command to run the cpplint.py script
#   - Assigns the command to the console as a shortcut
#*******************************************************************************

echo "Cloning the cpplint Repository from Github to root directory...\n"
cd ~
git clone https://github.com/google/styleguide

echo "Assigning cpplint as a shortcut to the console...\n"
echo "alias cpplint=\"python ~/styleguide/cpplint/cpplint.py\"" >> ~/.bashrc

echo "To use: cpplint <c++ file>\n"

