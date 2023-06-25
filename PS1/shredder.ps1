param (
    [Parameter(Mandatory=$true, Position=0)]
    #[ValidateScript({Test-Path $_ -or $_ -is [System.IO.FileInfo]})]
    [string]$Path
)

function SecureDeleteFile($filePath) {
    $bytesToWrite = [byte[]](0..255)
    $fs = New-Object System.IO.FileStream($filePath, 'Open', 'ReadWrite')
    try {
        $fs.SetLength(0)
        $fs.Write($bytesToWrite, 0, $bytesToWrite.Length)
        $fs.Flush()
        $fs.SetLength(0)
    } finally {
        $fs.Close()
        $fs.Dispose()
    }
}

function SecureDeleteDirectory($dirPath) {
    $files = Get-ChildItem $dirPath -Force -Recurse
    foreach ($file in $files) {
        if ($file.PSIsContainer) {
            SecureDeleteDirectory $file.FullName
        } else {
            SecureDeleteFile $file.FullName
        }
    }

    Remove-Item $dirPath -Force -Recurse
}

if ((Get-Item $Path).PSIsContainer) {
    SecureDeleteDirectory $Path
} else {
    SecureDeleteFile $Path
}