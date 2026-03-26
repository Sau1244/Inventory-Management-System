#pragma once

#include <iostream>

class InventoryException : public std::runtime_error{
public:
    explicit InventoryException(const std::string& msg) : std::runtime_error(msg) {}
};

class ItemNotFoundException : public InventoryException{
public:
    explicit ItemNotFoundException(const std::string& itemID)
                : InventoryException("Item with ID '" + itemID + "' not found.") {}
};

class DuplicateItemException : public InventoryException{
public:
    explicit DuplicateItemException(const std::string& itemID)
                : InventoryException("Item with ID '" + itemID + "' already exists in inventory.") {}
};

class InvalidValueException : public InventoryException{
public:
    explicit InvalidValueException(const std::string& msg) : InventoryException(msg) {}
};

class OperationCancelled : public std::runtime_error{
public:
    explicit OperationCancelled() : std::runtime_error("Operation Cancelled.") {}
};