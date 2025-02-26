class me
{
    this.hello = {
        console.log("hi");
    }
}

const akash = new me();
console.log(typeof akash);
akash.hello();
akash.__proto__.hello = () => { console.log("improved greeting!"); };
const akash1 = new me();

akash1.hello(); // improved greeting!
