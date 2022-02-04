Write-Host -ForegroundColor Green "This script will generate FAKE Credit Card numbers and output them to a file"
$size = Read-Host "How many numbers would you like to generate" 


$i=0
for(;$i -le $size; $i++)
{
    $first = Get-Random -Minimum 1000 -Maximum 9990
    $second = Get-Random -Minimum 1000 -Maximum 9999
    $third = Get-Random -Minimum 1000 -Maximum 9999
    $fourth = Get-Random -Minimum 1000 -Maximum 9999
    $number = -join($first, " ", $second, " ", $third, " ", $fourth);
    Write-Host $number
    Add-Content -Path .\DLP_test_fake_cc_numbers.txt -Value $number
}