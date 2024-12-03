#! /opt/homebrew/bin/fish

cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -DCMAKE_BUILD_TYPE=Debug -S . -B build/debug

# Needed for neovim clangd lsp
if test -L compile_commands.json
    rm compile_commands.json # Remove existing symlink if it exists
end
ln -s build/debug/compile_commands.json compile_commands.json # Create symlink for neovim lspconfig clangd

make -C build/debug

./build/debug/aoc $argv
