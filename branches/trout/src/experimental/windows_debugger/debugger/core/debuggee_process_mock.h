// Copyright (c) 2011 The Native Client Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#ifndef DEBUGGER_CORE_DEBUGGEE_PROCESS_MOCK_H_
#define DEBUGGER_CORE_DEBUGGEE_PROCESS_MOCK_H_
#include <deque>
#include "debugger/core/debuggee_iprocess.h"

namespace debug {
/// Mock of DebuggeeProcess.
///
/// Used in DebuggeeBreakpoint and DebuggeeThread unit tests.
/// Provides ReadMemory and WriteMemory methods that access
/// internal buffer, not debuggee process memory.
/// Other methods are stubs.
class DebuggeeProcessMock : public IDebuggeeProcess {
 public:
  /// Mock memory buffer is filled with this character.
  static const unsigned char kFillChar = 0xA7;
  static const int kMemSize = 1000;

  /// Fills mock memory buffer is filled with kFillChar.
  explicit DebuggeeProcessMock(DebugAPI* debug_api);

  virtual DebugAPI& debug_api() { return *debug_api_; }

  /// Reads bytes from |buff_|.
  /// @return false if it tries to read outside of |buff_|.
  virtual bool ReadMemory(const void* addr, size_t size, void* destination);

  /// Writes bytes to |buff_|.
  /// @return false if it tries to write outside of |buff_|.
  virtual bool WriteMemory(const void* addr, size_t size, const void* source);

  virtual int id() const { return 0;}
  virtual State state() const { return kDead; }
  virtual void* nexe_mem_base() const { return nexe_mem_base_; }
  virtual void set_nexe_mem_base(void* addr) { nexe_mem_base_ = addr; }
  virtual void* nexe_entry_point() const { return nexe_entry_point_; }
  virtual void set_nexe_entry_point(void* addr) { nexe_entry_point_ = addr; }
  virtual int GetWordSizeInBits() { return 0; }
  virtual bool IsWoW() { return 0;}
  virtual void Continue() {}
  virtual void ContinueAndPassExceptionToDebuggee() {}
  virtual void SingleStep() {}
  virtual void Break() {}
  virtual void Kill() {}
  virtual void Detach() {}
  virtual DebuggeeThread* GetThread(int id) { return NULL; }
  virtual DebuggeeThread* GetHaltedThread() { return NULL; }
  virtual void GetThreadIds(std::deque<int>* threads) const {}
  virtual bool SetBreakpoint(void* addr) { return false; }
  virtual bool RemoveBreakpoint(void* addr) { return false; }
  virtual Breakpoint* GetBreakpoint(void* addr) { return NULL; }
  virtual void GetBreakpoints(std::deque<Breakpoint*>* breakpoints) {}
  virtual void OnDebugEvent(DebugEvent* debug_event) {}
  virtual DebuggeeThread* AddThread(int id, HANDLE handle) { return NULL; }

 private:
  char buff_[kMemSize];
  DebugAPI* debug_api_;
  void* nexe_mem_base_;
  void* nexe_entry_point_;
};

}  // namespace debug

#endif  // DEBUGGER_CORE_DEBUGGEE_PROCESS_MOCK_H_

