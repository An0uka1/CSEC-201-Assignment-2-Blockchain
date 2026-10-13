#include <stdio.h>
#include <string.h>
#include "user.h"

struct User* getNode(struct User* head, int index) {
	struct User* current = head;
	while (current != NULL && index > 0) {
		current = current->next;
		index--;
	}
	return current;
}

struct User* buildChain(void) {
	struct User* head = NULL;
	head = add(head, "rob");
	head = add(head, "hanif");
	head = add(head, "gahyun");
	head = add(head, "matt");
	head = add(head, "sumita");
	head = add(head, "james");
	return head;
}

int main(void) {
	/*struct user * head=NULL;
	head = add(head, "rob");
	head = add(head, "hanif");
	head = add(head, "gahyun");
	head = add(head, "matt");
	head = add(head, "sumita");
	head = add(head, "james");
	verify(head);*/
	struct User* head = buildChain();

	printf("CTQ 2 1,2");
	printLog(head);

	printf("CTQ 2 3");
	verify(head);

	struct User* middle = getNode(head, 2);

	printf("CTQ 2 4");
	char savedName[20];
	strcpy(savedName, middle->Username);
	strcpy(middle->Username, "Gahyun");
	verify(head);
	strcpy(middle->Username, savedName);

	printf("CTQ 2 5");
	int savedSecond = middle->localLoginTime.tm_sec;
	middle->localLoginTime.tm_sec = savedSecond + 1;
	verify(head);
	middle->localLoginTime.tm_sec = savedSecond;

	printf("CTQ 2 6");
	unsigned char savedHash = middle->hash.hash0;
	middle->hash.hash0 = savedHash + 1;
	verify(head);
	middle->hash.hash0 = savedHash;
}