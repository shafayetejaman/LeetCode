class product:
    def __init__(self, Product_name, price, quantity, color=None) -> None:
        self.Product_name = Product_name
        self.price = price
        self.quantity = quantity
        self.color = color

    def __repr__(self) -> str:
        return f"Here is Your Product Name: {self.Product_name} Price: {self.price} Quantity: {self.quantity} Color: {self.color}"


class Shop:
    def __init__(self, name):
        self.name = name
        self.product = []

    def __repr__(self) -> str:
        return f"Shop name {self.name} Here is all Product {self.product}"

    def add_product(self, Product_name, price, quantity, color=None):

        products = product(Product_name, price, quantity, color)
        self.product.append(products)

    def buy_product(self, taka, product_name, buy_quantity):
        # self.taka=taka

        for item in self.product:

            if item.Product_name.lower() == product_name.lower():
                if item.quantity >= buy_quantity:
                    cost = item.price * buy_quantity
                    if taka >= cost:
                        item.quantity -= buy_quantity

                    else:
                        return f"Please Provide More Money{cost-taka}"

                else:
                    return f"Sorry Only {item.quantity} unit {product_name} avialable"

        return f"Sorry Product is not available"


hk = Shop("Hossain_kobir")
hk.add_product("Mobile", 12000, 10, "black")
hk.add_product("Laptop", 12000, 10)

print(hk.buy_product(15000, "Mobile", 11))
print(hk.buy_product(15000, "Laptop", 1))

# # print("please enter your name")
# # name=input()
# # print("please enter your taka")
# # taka=int(input())
# # # hk=Shop("Hossain_kobir",12000)
# # hk=Shop("name",taka)
# # print("Product Name:")
# # productName=input()
# # print("Price:")
# # productPrice=int(input())
# # print("Product Quantity")
# # product_quantity=int(input())
# # print("Color:")
# # productColor=input()
# # # hk.add_product("laptop",2300000,2,"Black")
# # # hk.add_product("Mobile",230000,2,"Silver")
# # hk.add_product(productName,productPrice,product_quantity,productColor)
# while True:
#     print("press 1 to add product")
#     print("press 2 to create a shopping chart")
#     print("press 3 to buy product")
#     print("press 4 to terminate the program")
#     num=int(input())
#     if num==1:
#         print("Now You Can Add Product In Your Shop")
#         print("Please Provide Shopkeeper Name")
#         name=input()
#         print("Now Please Share Your Investment ammount")
#         taka=int(input())
#         seller=Shop(name,taka)

#         print("Now Please Enter Your Product Name Which are you want to add in your shop")
#         name=input()

#         print("Each Product Price")
#         price=int(input())

#         print("Please Provied your Product Quantity")
#         quantity=int(input())

#         print("If You Have Any Product Color")
#         color=input()
#         seller.add_product(name,price,quantity,color)

#     if num==2:
#         pass
#     if num==3:
#         pass
#     if num==4:
#         print("Are you sure terminate this program \n type yes or no")
#         y=input()
#         if y == 'yes':
#             break

# print(seller)
