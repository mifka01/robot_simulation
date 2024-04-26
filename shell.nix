let
  pkgs = import <nixpkgs> {};
in
pkgs.mkShell {
  name = "ICP";
  buildInputs = [
    pkgs.qt5.full
    pkgs.cmake
  ];
}
