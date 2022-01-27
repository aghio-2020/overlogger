#include "CallStackImpl.h"
#include "ICallStackFrame.h"

namespace olg
{
    CallStackImpl::CallStackImpl(std::vector<std::unique_ptr<ICallStackFrame>>&& frames)
    : mCallStackFrames{std::forward<std::vector<std::unique_ptr<ICallStackFrame>>>(frames)}
    {
    }

    CallStackImpl::~CallStackImpl() = default;

    size_t CallStackImpl::getSize() const
    {
        return mCallStackFrames.size();
    }
    const ICallStackFrame &CallStackImpl::getFrame(size_t index) const
    {
        return *(mCallStackFrames[index]);
    }
    const std::vector<std::unique_ptr<ICallStackFrame>> &CallStackImpl::getFrameList() const
    {
        return mCallStackFrames;
    }
}