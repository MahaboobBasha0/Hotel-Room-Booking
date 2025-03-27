 #include <stdio.h>
#define GST_RATE 0.18 
#define MAX_ROOMS 5

typedef struct {
    int roomNumber;
    char acType[10];
    float costPerDay;   
    int isBooked;       
} Room;

void displayRooms(Room rooms[]) {
    printf("\nAvailable Rooms:\n");
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (!rooms[i].isBooked) {
            printf("Room %d - %s - %.2f/day\n", rooms[i].roomNumber, rooms[i].acType, rooms[i].costPerDay);
        }
    }
}

void bookRoom(Room rooms[]) {
    int roomNumber, days;
    printf("\nEnter Room Number to Book: ");
    scanf("%d", &roomNumber);

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].roomNumber == roomNumber && !rooms[i].isBooked) {
            printf("Enter Number of Days: ");
            scanf("%d", &days);

            float totalCost = rooms[i].costPerDay * days;
            float gst = totalCost * GST_RATE;
            float finalCost = totalCost + gst;

            rooms[i].isBooked = 1; 

            printf("\nRoom %d booked successfully!\nBase Cost: %.2f\nGST: %.2f\nTotal Cost: %.2f\n", roomNumber, totalCost, gst, finalCost);
            return;
        }
    }
    printf("Room %d is not available.\n", roomNumber);
}

int main() {
    Room rooms[MAX_ROOMS] = {
        {1, "AC", 2000.0, 0},
        {2, "Non-AC", 1500.0, 0},
        {3, "AC", 2000.0, 0},
        {4, "Non-AC", 1500.0, 0},
        {5, "AC", 2000.0, 0}
    };

    int choice;
    do {
        printf("\n KING HOTEL\n1. Display Rooms\n2. Book Room\n3. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayRooms(rooms);
                break;
            case 2:
                bookRoom(rooms);
                break;
            case 3:
                printf("Thank you!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 3);

    return 0;
}

