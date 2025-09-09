# gerarsenha

gerarsenha is a simple command-line password generator written in C.
By default, it prints to standard output a random 16 character password, which may include majuscules, minuscules, numerals and symbols.

## Installation

```sh
# Clone the repo
git clone https://github.com/lucassanginetto/gerarsenha.git

# Make sure you're inside the gerarsenha directory
cd gerarsenha

# Compile and install
sudo make install
```

## Usage

```sh
# Generate password with default options
gerarsenha

# Generate an 8 character password
gerarsenha --length=8
gerarsenha -l8

# Generate a password which contains only letters
gerarsenha --no-numerals --no-symbols
gerarsenha -ns

# Generate a 4 digit PIN
gerarsenha --no-majuscules --no-minuscules --no-symbols --length=4
gerarsenha -Mmsl4
```

## Uninstallation

```sh
# Make sure you're inside the gerarsenha directory
cd gerarsenha

# Uninstall
sudo make uninstall
```
