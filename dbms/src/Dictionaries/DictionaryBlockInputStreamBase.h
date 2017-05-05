#pragma once
#include <DataStreams/IProfilingBlockInputStream.h>

namespace DB 
{

class DictionaryBlockInputStreamBase : public IProfilingBlockInputStream
{
protected:
    Block block;

    String getID() const override;

private:
    bool was_read = false;

    Block readImpl() override;
    void readPrefixImpl() override { was_read = false; }
    void readSuffixImpl() override { was_read = false; }
};

}
