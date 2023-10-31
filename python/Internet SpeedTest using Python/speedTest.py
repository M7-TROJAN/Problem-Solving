import os
from speedtest import Speedtest

def perform_speed_test():
    # Create an instance of Speedtest
    wifi_speed = Speedtest()

    # Get the download and upload speeds
    download_speed = wifi_speed.download()
    upload_speed = wifi_speed.upload()

    clear_console()

    # Print the download and upload speeds in Mbps
    print_speed("Download Speed", convert_to_mbps(download_speed))
    print_speed("Upload Speed", convert_to_mbps(upload_speed))

def convert_to_mbps(speed_in_bytes):
    # Convert speed from bytes to megabits per second (Mbps)
    return (speed_in_bytes / 1024 / 1024)

def print_speed(speed_type, speed_value):
    # Display the speed value with the type (Download/Upload) in Mbps
    print(f"{speed_type}: {speed_value:.2f} Mbps")

def clear_console():
    # Clear the console screen based on the operating system
    os.system('cls' if os.name == 'nt' else 'clear')

def main():
    perform_speed_test()

if __name__ == "__main__":
    main()
