
async function printNumber(num)
{
    return new Promise((resolve, reject) =>
    {
        setTimeout(() => resolve(num), 2000)
    })

}

console.log(1)
console.log(2)
const num = await printNumber(3)
console.log(num)
console.log(4)
console.log(5)