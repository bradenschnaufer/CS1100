#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_CONTACT_NAME_LENGTH 50
#define MAX_PHONE_NUMBER_LENGTH 15
#define MAX_EMAIL_ADDRESS_LENGTH 50

// creating a struct to create a clearer code
struct contact_info {
  char name[MAX_CONTACT_NAME_LENGTH];
  char phone[MAX_PHONE_NUMBER_LENGTH];
  char email[MAX_EMAIL_ADDRESS_LENGTH];
};

// Name Functions
void list_contacts(struct contact_info contacts[], int count);
void select_contact(struct contact_info contacts[], int count);

int main(void) {

  struct contact_info contacts[MAX_CONTACTS];
  int choice;
  int contact_count = 1;
  char line[256];

  FILE *filePtr;
  filePtr = fopen("phone_contacts.csv", "r");
  if (filePtr == NULL) {
    printf("Failed to open the file.\n");
    return 1;
  }
  // Read contacts from file
  while (contact_count < MAX_CONTACTS &&
         fgets(line, sizeof(line), filePtr) != NULL) {
    // Remove the newline character from the end of the line
    line[strcspn(line, "\n")] = '\0';

    // Parse the name phone number and email
    sscanf(line, "%49[^,],%14[^,],%49[^\n]", contacts[contact_count].name,
           contacts[contact_count].phone, contacts[contact_count].email);

    contact_count++;

    if (contact_count >= MAX_CONTACTS) {
      break;
    }
  }

  // menu
  do {
    printf("Smartphone Contact Hub\n");
    printf("1. List Contacts\n");
    printf("2. Select Contact\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1: {
      // list contacts
      list_contacts(contacts, contact_count);
      break;
    }

    case 2: {
      // select contact
      select_contact(contacts, contact_count);
      break;
    }

    case 3: {
      // exit
      printf("Exiting the Smartphone Contact Hub.\n");
      printf("\n");
      break;
    }

    default:
      // not vailid
      printf("Invalid choice. Please try again.\n\n");
      break;
    }
  } while (choice != 3);

  return 0;
}

void list_contacts(struct contact_info contacts[], int count) {

  printf("Phone Contacts:\n");
  for (int i = 1; i < count; i++) {
    // phonecontacts
    printf("%d. Name: %s\n", i, contacts[i].name);
    // phone
    printf("   Phone: %s\n", contacts[i].phone);
    // email
    printf("   Email: %s\n\n", contacts[i].email);
  }
  printf("\n");
}

void select_contact(struct contact_info contacts[], int count) {
  // display contacts
  int selection;
  printf("Enter the contact index: ");
  scanf("%d", &selection);

  if (selection < 1 || selection >= 5) {
    printf("Invalid contact index.\n\n");
    return;
  }
  printf("Selected Contact:\n");
  printf("Name: %s\n", contacts[selection].name);
  printf("Phone: %s\n", contacts[selection].phone);
  printf("Email: %s\n", contacts[selection].email);

  int option;
  printf("What would you like to do?\n");
  printf("1. Call\n2. Send Email\n");
  printf("Enter your choice: ");
  scanf("%d", &option);

  switch (option) {
  case 1:
    printf("Calling %s...\n", contacts[selection].name);
    printf("\n");
    break;

  case 2:
    printf("Sending email to %s...\n", contacts[selection].email);
    printf("\n");
    break;

  default:
    printf("Invalid choice please try again.");
    break;
  }
}
