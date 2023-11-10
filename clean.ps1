rm *.vcxproj
rm *.vcxproj.filters
rm *.sln
rm *.cmake
$paths = 'CMakeFiles', '_deps', 'CMakeCache.txt'
foreach ($path in $paths) {
    if (Test-Path $path) {
      rm -Force -Recurse $path
    }
}
