require 'book_test_helper'
class PartTest < Test::Unit::TestCase
  include BookTestHelper

  def test_initialize
    part = Book::Part.new(nil, nil, nil)
    assert_equal nil, part.number
    assert_equal nil, part.chapters
    assert_equal '', part.name

    part = Book::Part.new(nil, 123, [], 'name')
    assert_equal 123, part.number
    assert_equal [], part.chapters
    assert_equal 'name', part.name
  end

  def test_each_chapter
    part = Book::Part.new(nil, nil, [1, 2, 3])

    tmp = []
    part.each_chapter do |ch|
      tmp << ch
    end
    assert_equal [1, 2, 3], tmp
  end

  def test_volume
    part = Book::Part.new(nil, nil, [])
    assert part.volume
    assert_equal 0, part.volume.bytes
    assert_equal 0, part.volume.chars
    assert_equal 0, part.volume.lines

    chs = []
    Tempfile.open('part_test') do |o|
      o.print "12345"
      chs << Book::Chapter.new(nil, nil, nil, o.path)
    end
    Tempfile.open('part_test') do |o|
      o.print "67890"
      chs << Book::Chapter.new(nil, nil, nil, o.path)
    end

    part = Book::Part.new(nil, nil, chs)
    assert part.volume
    assert part.volume.bytes > 0
    assert part.volume.chars > 0
    assert part.volume.lines > 0
  end
end
