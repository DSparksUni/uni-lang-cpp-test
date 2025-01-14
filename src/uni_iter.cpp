#include "uni_iter.hpp"

namespace uni {
    FileIterator::FileIterator(const std::string& src) noexcept:
        content(src), c(src[0]), m_done(false) {}

    [[nodiscard]] char FileIterator::getchar() const noexcept {
        return c;
    }
    [[nodiscard]] bool FileIterator::done() const noexcept {
        return m_done;
    }
    [[nodiscard]] size_t FileIterator::line() const noexcept {
        return m_pos.line;
    }
    [[nodiscard]] size_t FileIterator::col() const noexcept {
        return m_pos.col;
    }
    [[nodiscard]] size_t FileIterator::serial() const noexcept {
        return m_pos.serial;
    }
    [[nodiscard]] Pos FileIterator::pos() const noexcept {
        return m_pos;
    }

    void FileIterator::advance() noexcept {
        m_pos.serial++;

        if(m_pos.serial >= content.size())
            m_done = true;
        else {
            c = content[m_pos.serial];
            if(c == '\n') {
                m_pos.line++;
                m_pos.col = 0;
            } else m_pos.col++;
        }
    }
}
