Node *getNodeAt(Node *head, int index)
// {
//     int counter = 0;
//     Node *current = head;
//     while (current != nullptr && counter < index)
//     {
//         current = current->next;
//         counter++;
//     }
//     return current;
// }
// int getNodeIndex(Node *head, Node *target)
// {
//     int index = 0;
//     Node *current = head;

//     while (current != nullptr)
//     {
//         if (current == target)
//         {
//             return index;
//         }
//         current = current->next;
//         index++;
//     }
//     return -1; // If the target node is not found
// }