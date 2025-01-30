
def main():
    # Display welcome message
    print("Welcome to Shamwowzer, the world¡¯s most absorbent shammy!")
    
    # Capture order details
    num_shamwowzers = order_capture()

    # Calculate subtotal
    subtotal_cost = subtotal(num_shamwowzers)

    # Calculate shipping and handling costs
    shipping_cost = shipping_and_handling(num_shamwowzers)

    # Calculate total amount due
    total_cost = subtotal_cost + shipping_cost

    # Display the results
    print(f"You ordered {num_shamwowzers}. Your subtotal is ${subtotal_cost:.2f}, "
          f"shipping and handling is ${shipping_cost:.2f}, and the total amount due is ${total_cost:.2f}")


def order_capture():
    # Get the number of Shamwowzers the customer would like to order
    while True:
        try:
            num_shamwowzers = int(input("Enter the number of Shamwowzers sold: "))
            if num_shamwowzers <= 0:
                print("Please enter a positive number.")
            else:
                return num_shamwowzers
        except ValueError:
            print("Invalid input. Please enter a number.")


def subtotal(num_shamwowzers):
    # Calculate the subtotal
    if num_shamwowzers >= 10:
        return num_shamwowzers * 10.00  # Discount price for 10 or more
    else:
        return num_shamwowzers * 13.00  # Regular price for less than 10


def shipping_and_handling(num_shamwowzers):
    # Shipping and handling is $3.00 per Shamwowzer
    return num_shamwowzers * 3.00

