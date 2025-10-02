template <typename T>
void DoublyList<T>::append(const T& elem) {
    Node* n = new Node(elem, trailer, trailer->prev);
    trailer->prev->next = n;
    trailer->prev = n;
    this->length++;
}

template <typename T>
T DoublyList<T>::getElement(int position) const {
    if (position < 0 || position >= this->length) {
        throw string("getElement: position out of bounds");
    }
    Node* curr = header->next;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    return curr->value;
}

template <typename T>
void DoublyList<T>::insert(int position, const T& elem) {
    if (position < 0 || position > this->length) {
        throw string("insert: position out of bounds");
    }
    Node* curr = header;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    Node* n = new Node(elem, curr->next, curr);
    curr->next->prev = n;
    curr->next = n;
    this->length++;
}

template <typename T>
void DoublyList<T>::remove(int position) {
    if (position < 0 || position >= this->length) {
        throw string("remove: position out of bounds");
    }
    Node* curr = header->next;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    this->length--;
}

template <typename T>
bool DoublyList<T>::search(const T& elem) const {
    Node* curr = header->next;
    while (curr != trailer) {
        if (curr->value == elem) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

template <typename T>
void DoublyList<T>::replace(int position, const T& elem) {
    if (position < 0 || position >= this->length) {
        throw string("replace: position out of bounds");
    }
    Node* curr = header->next;
    for (int i = 0; i < position; i++) {
        curr = curr->next;
    }
    curr->value = elem;
}
