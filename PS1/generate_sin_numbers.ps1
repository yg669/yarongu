Write-Host -ForegroundColor Green "This script will generate FAKE SIN numbers and output them to a file"
$size = Read-Host "How many numbers would you like to generate" 


$i=0
for(;$i -le $size; $i++)
{
    $first = Get-Random -Minimum 100 -Maximum 999
    $second = Get-Random -Minimum 100 -Maximum 999
    $third = Get-Random -Minimum 100 -Maximum 999
    $number = -join($first, " ", $second, " ", $third);
    Write-Host $number
    Add-Content -Path .\DLP_test_fake_sin_numbers.txt -Value $number
}

