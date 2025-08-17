# Ứng dụng Giám sát Hệ thống

## Tổng quan
Đây là một ứng dụng giám sát hệ thống được phát triển bằng ngôn ngữ C theo kiến trúc Model-View-Controller (MVC). Ứng dụng thu thập và hiển thị các chỉ số hệ thống theo thời gian thực, bao gồm mức sử dụng CPU, RAM, dung lượng đĩa, thông tin mạng, và các thông số hệ thống khác. Dự án hỗ trợ các tính năng như cảnh báo, ghi log, sao lưu cấu hình, và có thể mở rộng để tích hợp với các hệ thống giám sát khác.


## Tính năng
- **Model**: Quản lý dữ liệu hệ thống (CPU, RAM, đĩa, mạng, v.v.).
- **View**: Hiển thị bảng điều khiển với các chỉ số hệ thống thời gian thực.
- **Controller**: Xử lý đầu vào người dùng, tần suất làm mới và quản lý cấu hình.
- **Tính năng Nâng cao**:
  - Cài đặt ngưỡng cảnh báo cho CPU và nhiệt độ.
  - Ghi log các sự kiện quan trọng vào file.
  - Sao lưu và khôi phục cấu hình.
