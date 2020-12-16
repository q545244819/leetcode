function wordPattern(pattern: string, s: string): boolean {
  const strs: string[] = s.split(" ");
  const book = new Map<string, string>();
  const visited = new Map<string, string>();

  if (pattern.length !== strs.length) {
    return false;
  }

  for (let i = 0; i < pattern.length; i++) {
    if (book.has(pattern[i]) && book.get(pattern[i]) !== strs[i]) {
      return false;
    }
    if (visited.has(strs[i]) && visited.get(strs[i]) !== pattern[i]) {
      return false;
    }

    book.set(pattern[i], strs[i]);
    visited.set(strs[i], pattern[i]);
  }

  return true;
}
