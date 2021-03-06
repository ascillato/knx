#pragma once

#include "table_object.h"

class AssociationTableObject: public TableObject
{
public:
    AssociationTableObject(uint8_t* memoryReference);
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Woverloaded-virtual"
    void readProperty(PropertyID id, uint32_t start, uint32_t& count, uint8_t* data);
    #pragma GCC diagnostic pop
    uint16_t entryCount();
    uint16_t operator[](uint16_t idx);
    uint8_t* save(uint8_t* buffer);
    uint8_t* restore(uint8_t* buffer);

    int32_t translateAsap(uint16_t asap);
protected:
    void beforeStateChange(LoadState& newState);
    uint8_t propertyCount();
    PropertyDescription* propertyDescriptions();
private:
    uint16_t* _tableData;
};