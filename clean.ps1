rm *.vcxproj
rm *.vcxproj.filters
rm *.sln
rm *.cmake
rm *.dll
rm *.exe
$paths = 'Makefile', 'CMakeFiles', '_deps', 'CMakeCache.txt'
foreach ($path in $paths) {
    if (Test-Path $path) {
      rm -Force -Recurse $path
    }
}
