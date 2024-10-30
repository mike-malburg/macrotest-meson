$buildDir = "builddir"
Write-Host $buildDir
if(Test-Path $buildDir) {
   Write-Host "Removing: $buildDir..."
   Remove-Item -Recurse -Force $buildDir
}
$dir = (New-Item $buildDir -ItemType Directory).FullName
Write-Host "Building to: $dir"
meson setup builddir --prefix=$dir
Push-Location $dir
meson compile
meson test --verbose
meson install
Pop-Location

